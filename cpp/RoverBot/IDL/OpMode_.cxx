// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file OpMode_.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "OpMode_.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

OpMode_::OpMode_()
{
    // m_OpMode com.eprosima.idl.parser.typecode.StringTypeCode@25af5db5
    m_OpMode ="";

}

OpMode_::~OpMode_()
{
}

OpMode_::OpMode_(const OpMode_ &x)
{
    m_OpMode = x.m_OpMode;
}

OpMode_::OpMode_(OpMode_ &&x)
{
    m_OpMode = std::move(x.m_OpMode);
}

OpMode_& OpMode_::operator=(const OpMode_ &x)
{

    m_OpMode = x.m_OpMode;

    return *this;
}

OpMode_& OpMode_::operator=(OpMode_ &&x)
{

    m_OpMode = std::move(x.m_OpMode);

    return *this;
}

size_t OpMode_::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    return current_alignment - initial_alignment;
}

size_t OpMode_::getCdrSerializedSize(const OpMode_& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.OpMode().size() + 1;

    return current_alignment - initial_alignment;
}

void OpMode_::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_OpMode;
}

void OpMode_::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_OpMode;
}

/*!
 * @brief This function copies the value in member OpMode
 * @param _OpMode New value to be copied in member OpMode
 */
void OpMode_::OpMode(const std::string &_OpMode)
{
m_OpMode = _OpMode;
}

/*!
 * @brief This function moves the value in member OpMode
 * @param _OpMode New value to be moved in member OpMode
 */
void OpMode_::OpMode(std::string &&_OpMode)
{
m_OpMode = std::move(_OpMode);
}

/*!
 * @brief This function returns a constant reference to member OpMode
 * @return Constant reference to member OpMode
 */
const std::string& OpMode_::OpMode() const
{
    return m_OpMode;
}

/*!
 * @brief This function returns a reference to member OpMode
 * @return Reference to member OpMode
 */
std::string& OpMode_::OpMode()
{
    return m_OpMode;
}

size_t OpMode_::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;



    return current_align;
}

bool OpMode_::isKeyDefined()
{
   return false;
}

void OpMode_::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
}
