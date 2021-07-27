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
 * @file Route_.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _ROUTE__H_
#define _ROUTE__H_

// TODO Poner en el contexto.
#include "NavPose2d_.h"

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
#if defined(Route__SOURCE)
#define Route__DllAPI __declspec( dllexport )
#else
#define Route__DllAPI __declspec( dllimport )
#endif // Route__SOURCE
#else
#define Route__DllAPI
#endif
#else
#define Route__DllAPI
#endif // _WIN32

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure Route_ defined by the user in the IDL file.
 * @ingroup ROUTE_
 */
class Route_
{
public:

    /*!
     * @brief Default constructor.
     */
    eProsima_user_DllExport Route_();

    /*!
     * @brief Default destructor.
     */
    eProsima_user_DllExport ~Route_();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object Route_ that will be copied.
     */
    eProsima_user_DllExport Route_(const Route_ &x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object Route_ that will be copied.
     */
    eProsima_user_DllExport Route_(Route_ &&x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object Route_ that will be copied.
     */
    eProsima_user_DllExport Route_& operator=(const Route_ &x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object Route_ that will be copied.
     */
    eProsima_user_DllExport Route_& operator=(Route_ &&x);

    /*!
     * @brief This function copies the value in member m_waypoints
     * @param _m_waypoints New value to be copied in member m_waypoints
     */
    eProsima_user_DllExport void m_waypoints(const std::vector<NavPose2d_> &_m_waypoints);

    /*!
     * @brief This function moves the value in member m_waypoints
     * @param _m_waypoints New value to be moved in member m_waypoints
     */
    eProsima_user_DllExport void m_waypoints(std::vector<NavPose2d_> &&_m_waypoints);

    /*!
     * @brief This function returns a constant reference to member m_waypoints
     * @return Constant reference to member m_waypoints
     */
    eProsima_user_DllExport const std::vector<NavPose2d_>& m_waypoints() const;

    /*!
     * @brief This function returns a reference to member m_waypoints
     * @return Reference to member m_waypoints
     */
    eProsima_user_DllExport std::vector<NavPose2d_>& m_waypoints();

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
    eProsima_user_DllExport static size_t getCdrSerializedSize(const Route_& data, size_t current_alignment = 0);


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
    std::vector<NavPose2d_> m_m_waypoints;
};

#endif // _ROUTE__H_