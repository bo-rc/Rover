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
 * @file Power_.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _POWER__H_
#define _POWER__H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <bitset>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#if defined(Power__SOURCE)
#define Power__DllAPI __declspec( dllexport )
#else
#define Power__DllAPI __declspec( dllimport )
#endif // Power__SOURCE
#else
#define Power__DllAPI
#endif
#else
#define Power__DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure Power_ defined by the user in the IDL file.
 * @ingroup POWER_
 */
class Power_
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Power_();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Power_();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Power_ that will be copied.
     */
    eProsima_user_DllExport Power_(const Power_ &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Power_ that will be copied.
     */
    eProsima_user_DllExport Power_(Power_ &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Power_ that will be copied.
     */
    eProsima_user_DllExport Power_& operator=(const Power_ &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Power_ that will be copied.
     */
    eProsima_user_DllExport Power_& operator=(Power_ &&x);

    /*!
     * @brief This function sets a value in member boardVolt
     * @param _boardVolt New value for member boardVolt
     */
    eProsima_user_DllExport void boardVolt(float _boardVolt);

    /*!
     * @brief This function returns the value of member boardVolt
     * @return Value of member boardVolt
     */
    eProsima_user_DllExport float boardVolt() const;

    /*!
     * @brief This function returns a reference to member boardVolt
     * @return Reference to member boardVolt
     */
    eProsima_user_DllExport float& boardVolt();

    /*!
     * @brief This function sets a value in member railVolt
     * @param _railVolt New value for member railVolt
     */
    eProsima_user_DllExport void railVolt(float _railVolt);

    /*!
     * @brief This function returns the value of member railVolt
     * @return Value of member railVolt
     */
    eProsima_user_DllExport float railVolt() const;

    /*!
     * @brief This function returns a reference to member railVolt
     * @return Reference to member railVolt
     */
    eProsima_user_DllExport float& railVolt();

    /*!
     * @brief This function sets a value in member batVolt
     * @param _batVolt New value for member batVolt
     */
    eProsima_user_DllExport void batVolt(float _batVolt);

    /*!
     * @brief This function returns the value of member batVolt
     * @return Value of member batVolt
     */
    eProsima_user_DllExport float batVolt() const;

    /*!
     * @brief This function returns a reference to member batVolt
     * @return Reference to member batVolt
     */
    eProsima_user_DllExport float& batVolt();

    /*!
     * @brief This function sets a value in member batCurrent
     * @param _batCurrent New value for member batCurrent
     */
    eProsima_user_DllExport void batCurrent(float _batCurrent);

    /*!
     * @brief This function returns the value of member batCurrent
     * @return Value of member batCurrent
     */
    eProsima_user_DllExport float batCurrent() const;

    /*!
     * @brief This function returns a reference to member batCurrent
     * @return Reference to member batCurrent
     */
    eProsima_user_DllExport float& batCurrent();


    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    eProsima_user_DllExport static size_t getCdrSerializedSize(const Power_& data, size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serialize(eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void deserialize(eprosima::fastcdr::Cdr &cdr);



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    eProsima_user_DllExport static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    eProsima_user_DllExport static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    eProsima_user_DllExport void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

private:
    float m_boardVolt;
    float m_railVolt;
    float m_batVolt;
    float m_batCurrent;
};

#endif // _POWER__H_