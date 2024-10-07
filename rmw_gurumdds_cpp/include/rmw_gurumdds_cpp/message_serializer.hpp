#ifndef RMW_GURUMDDS__MESSAGE_SERIALIZER_HPP_
#define RMW_GURUMDDS__MESSAGE_SERIALIZER_HPP_

#include "rosidl_runtime_cpp/bounded_vector.hpp"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"
#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"
#include "rosidl_runtime_c/u16string.h"
#include "rosidl_runtime_c/u16string_functions.h"

#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"

#include "rosidl_typesupport_introspection_c/message_introspection.h"

#include "cdr_buffer.hpp"

namespace rmw_gurumdds_cpp
{
template<bool SERIALIZE, typename MessageMembersT>
class MessageSerializer {
public:
  using MessageMemberT = MessageMemberType<MessageMembersT>;

  static constexpr LanguageKind LANGUAGE_KIND = get_language_kind<MessageMemberT>();

  explicit MessageSerializer(CdrSerializationBuffer<SERIALIZE> & buffer);

  void serialize(const MessageMembersT * members, const uint8_t * input, bool roundup_);

private:
  void serialize_boolean(
    const MessageMemberT * member,
    const uint8_t * input);

  void serialize_wchar(
    const MessageMemberT * member,
    const uint8_t * input);

  void serialize_string(
    const MessageMemberT * member,
    const uint8_t * input);

  void serialize_wstring(
    const MessageMemberT * member,
    const uint8_t * input);


  void serialize_struct_arr(
    const MessageMemberT * member,
    const uint8_t * input);

  template<typename PrimitiveT>
  void serialize_primitive(
    const MessageMemberT * member,
    const uint8_t * input);
private:
  CdrSerializationBuffer<SERIALIZE> & buffer;
};
} // namespace rmw_gurumdds_cpp

#include "rmw_gurumdds_cpp/message_serializer.inl"

#endif  // RMW_GURUMDDS__MESSAGE_SERIALIZER_HPP_