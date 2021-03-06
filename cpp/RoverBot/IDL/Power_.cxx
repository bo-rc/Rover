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
 * @file Power_.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "Power_.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

Power_::Power_()
{
    // m_boardVolt com.eprosima.idl.parser.typecode.PrimitiveTypeCode@371a67ec
    m_boardVolt = 0.0;
    // m_railVolt com.eprosima.idl.parser.typecode.PrimitiveTypeCode@5ed828d
    m_railVolt = 0.0;
    // m_batVolt com.eprosima.idl.parser.typecode.PrimitiveTypeCode@50d0686
    m_batVolt = 0.0;
    // m_batCurrent com.eprosima.idl.parser.typecode.PrimitiveTypeCode@7a3d45bd
    m_batCurrent = 0.0;

}

Power_::~Power_()
{




}

Power_::Power_(const Power_ &x)
{
    m_boardVolt = x.m_boardVolt;
    m_railVolt = x.m_railVolt;
    m_batVolt = x.m_batVolt;
    m_batCurrent = x.m_batCurrent;
}

Power_::Power_(Power_ &&x)
{
    m_boardVolt = x.m_boardVolt;
    m_railVolt = x.m_railVolt;
    m_batVolt = x.m_batVolt;
    m_batCurrent = x.m_batCurrent;
}

Power_& Power_::operator=(const Power_ &x)
{

    m_boardVolt = x.m_boardVolt;
    m_railVolt = x.m_railVolt;
    m_batVolt = x.m_batVolt;
    m_batCurrent = x.m_batCurrent;

    return *this;
}

Power_& Power_::operator=(Power_ &&x)
{

    m_boardVolt = x.m_boardVolt;
    m_railVolt = x.m_railVolt;
    m_batVolt = x.m_batVolt;
    m_batCurrent = x.m_batCurrent;

    return *this;
}

size_t Power_::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

size_t Power_::getCdrSerializedSize(const Power_& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);



    return current_alignment - initial_alignment;
}

void Power_::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_boardVolt;
    scdr << m_railVolt;
    scdr << m_batVolt;
    scdr << m_batCurrent;
}

void Power_::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_boardVolt;
    dcdr >> m_railVolt;
    dcdr >> m_batVolt;
    dcdr >> m_batCurrent;
}

/*!
 * @brief This function sets a value in member boardVolt
 * @param _boardVolt New value for member boardVolt
 */
void Power_::boardVolt(float _boardVolt)
{
m_boardVolt = _boardVolt;
}

/*!
 * @brief This function returns the value of member boardVolt
 * @return Value of member boardVolt
 */
float Power_::boardVolt() const
{
    return m_boardVolt;
}

/*!
 * @brief This function returns a reference to member boardVolt
 * @return Reference to member boardVolt
 */
float& Power_::boardVolt()
{
    return m_boardVolt;
}

/*!
 * @brief This function sets a value in member railVolt
 * @param _railVolt New value for member railVolt
 */
void Power_::railVolt(float _railVolt)
{
m_railVolt = _railVolt;
}

/*!
 * @brief This function returns the value of member railVolt
 * @return Value of member railVolt
 */
float Power_::railVolt() const
{
    return m_railVolt;
}

/*!
 * @brief This function returns a reference to member railVolt
 * @return Reference to member railVolt
 */
float& Power_::railVolt()
{
    return m_railVolt;
}

/*!
 * @brief This function sets a value in member batVolt
 * @param _batVolt New value for member batVolt
 */
void Power_::batVolt(float _batVolt)
{
m_batVolt = _batVolt;
}

/*!
 * @brief This function returns the value of member batVolt
 * @return Value of member batVolt
 */
float Power_::batVolt() const
{
    return m_batVolt;
}

/*!
 * @brief This function returns a reference to member batVolt
 * @return Reference to member batVolt
 */
float& Power_::batVolt()
{
    return m_batVolt;
}

/*!
 * @brief This function sets a value in member batCurrent
 * @param _batCurrent New value for member batCurrent
 */
void Power_::batCurrent(float _batCurrent)
{
m_batCurrent = _batCurrent;
}

/*!
 * @brief This function returns the value of member batCurrent
 * @return Value of member batCurrent
 */
float Power_::batCurrent() const
{
    return m_batCurrent;
}

/*!
 * @brief This function returns a reference to member batCurrent
 * @return Reference to member batCurrent
 */
float& Power_::batCurrent()
{
    return m_batCurrent;
}


size_t Power_::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
    size_t current_align = current_alignment;







    return current_align;
}

bool Power_::isKeyDefined()
{
   return false;
}

void Power_::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
    (void) scdr;
     
     
     
     
}
