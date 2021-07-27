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
 * @file OpMode_.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _OPMODE__H_
#define _OPMODE__H_

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
#if defined(OpMode__SOURCE)
#define OpMode__DllAPI __declspec( dllexport )
#else
#define OpMode__DllAPI __declspec( dllimport )
#endif // OpMode__SOURCE
#else
#define OpMode__DllAPI
#endif
#else
#define OpMode__DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure OpMode_ defined by the user in the IDL file.
 * @ingroup OPMODE_
 */
class OpMode_
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport OpMode_();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~OpMode_();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object OpMode_ that will be copied.
     */
    eProsima_user_DllExport OpMode_(const OpMode_ &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object OpMode_ that will be copied.
     */
    eProsima_user_DllExport OpMode_(OpMode_ &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object OpMode_ that will be copied.
     */
    eProsima_user_DllExport OpMode_& operator=(const OpMode_ &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object OpMode_ that will be copied.
     */
    eProsima_user_DllExport OpMode_& operator=(OpMode_ &&x);

    /*!
     * @brief This function copies the value in member OpMode
     * @param _OpMode New value to be copied in member OpMode
     */
    eProsima_user_DllExport void OpMode(const std::string &_OpMode);

    /*!
     * @brief This function moves the value in member OpMode
     * @param _OpMode New value to be moved in member OpMode
     */
    eProsima_user_DllExport void OpMode(std::string &&_OpMode);

    /*!
     * @brief This function returns a constant reference to member OpMode
     * @return Constant reference to member OpMode
     */
    eProsima_user_DllExport const std::string& OpMode() const;

    /*!
     * @brief This function returns a reference to member OpMode
     * @return Reference to member OpMode
     */
    eProsima_user_DllExport std::string& OpMode();

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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const OpMode_& data, size_t current_alignment = 0);


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
    std::string m_OpMode;
};

#endif // _OPMODE__H_