#ifdef LT_HAS_LWIP

#include "LwIPRxBuffer.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#undef LWIP_COMPAT_SOCKETS
#define LWIP_COMPAT_SOCKETS 0
#include <lwip/sockets.h>

#ifdef __cplusplus
} // extern "C"
#endif

size_t LwIPRxBuffer::r_available() {
	if (_sock < 0) {
		return 0;
	}
	int count;
	int res = lwip_ioctl(_sock, FIONREAD, &count);
	if (res < 0) {
		_failed = true;
		return 0;
	}
	return count;
}

size_t LwIPRxBuffer::fillBuffer() {
	if (!_buffer) {
		_buffer = (uint8_t *)malloc(_size);
		if (!_buffer) {
			printf("[e] Not enough memory to allocate buffer\r\n");
			_failed = true;
			return 0;
		}
	}
	if (_fill && _pos == _fill) {
		_fill = 0;
		_pos  = 0;
	}
	if (!_buffer || _size <= _fill || !r_available()) {
		return 0;
	}
	int res = lwip_recv(_sock, _buffer + _fill, _size - _fill, MSG_DONTWAIT);
	if (res < 0) {
		if (errno != EWOULDBLOCK) {
			_failed = true;
		}
		return 0;
	}
	_fill += res;
	return res;
}

LwIPRxBuffer::LwIPRxBuffer(int sock, size_t size)
	: _size(size), _buffer(NULL), _pos(0), _fill(0), _sock(sock), _failed(false) {
	//_buffer = (uint8_t *)malloc(_size);
}

LwIPRxBuffer::~LwIPRxBuffer() {
	free(_buffer);
}

bool LwIPRxBuffer::failed() {
	return _failed;
}

int LwIPRxBuffer::read(uint8_t *dst, size_t len) {
	if (!dst || !len || (_pos == _fill && !fillBuffer())) {
		return _failed ? -1 : 0;
	}
	size_t a = _fill - _pos;
	if (len <= a || ((len - a) <= (_size - _fill) && fillBuffer() >= (len - a))) {
		if (len == 1) {
			*dst = _buffer[_pos];
		} else {
			memcpy(dst, _buffer + _pos, len);
		}
		_pos += len;
		return len;
	}
	size_t left	  = len;
	size_t toRead = a;
	uint8_t *buf  = dst;
	memcpy(buf, _buffer + _pos, toRead);
	_pos += toRead;
	left -= toRead;
	buf += toRead;
	while (left) {
		if (!fillBuffer()) {
			return len - left;
		}
		a	   = _fill - _pos;
		toRead = (a > left) ? left : a;
		memcpy(buf, _buffer + _pos, toRead);
		_pos += toRead;
		left -= toRead;
		buf += toRead;
	}
	return len;
}

int LwIPRxBuffer::peek() {
	if (_pos == _fill && !fillBuffer()) {
		return -1;
	}
	return _buffer[_pos];
}

size_t LwIPRxBuffer::available() {
	return _fill - _pos + r_available();
}

#endif
