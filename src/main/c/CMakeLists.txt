# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements. See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(bug-native)
SET(${PROJECT_NAME}_MAJOR_VERSION 1)
SET(${PROJECT_NAME}_MINOR_VERSION 0)
SET(${PROJECT_NAME}_PATCH_LEVEL 0)

FIND_PACKAGE(Java)
FIND_PACKAGE(JNI)
if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

# you may want to remove this next line for debugging
# -O3 would make inline debug hard
#ADD_DEFINITIONS("-O3 -Wall -z execstack")
ADD_DEFINITIONS("-O3 -Wall")
#ADD_DEFINITIONS("-fdump-tree-all -Wall -pg -g")

INCLUDE_DIRECTORIES(. ${JNI_INCLUDE_DIRS})

ADD_CUSTOM_COMMAND(
    OUTPUT org_apache_activemq_artemis_bug_BugContext.h
    COMMAND javah -cp ../java/ org.apache.activemq.artemis.bug.BugContext
    DEPENDS ../java/org/apache/activemq/artemis/bug/BugContext.java
)

ADD_LIBRARY(bug-native SHARED org_apache_activemq_artemis_bug_BugContext.c org_apache_activemq_artemis_bug_BugContext.h)

set_target_properties(bug-native PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ../../../bin)
