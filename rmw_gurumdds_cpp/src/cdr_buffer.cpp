#include <cassert>
#include "rmw_gurumdds_cpp/cdr_buffer.hpp"

namespace rmw_gurumdds_cpp
{
CdrBuffer::CdrBuffer(uint8_t * buf, size_t size)
  : buf_{buf}
  , offset_{}
  , size_{size} {

}

size_t CdrBuffer::get_offset() const {
  return offset_;
}

void CdrBuffer::roundup(uint32_t align) {
  assert(align != 0);
  size_t count = -offset_ & (align - 1);
  if (offset_ + count > size_) {
    throw std::runtime_error("Out of buffer");
  }

  advance(count);
}

void CdrBuffer::advance(size_t cnt) {
  offset_ += cnt;
}
} // namespace rmw_gurumdds_cpp