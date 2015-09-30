/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package org.apache.activemq.artemis.bug;

import java.util.concurrent.atomic.AtomicLong;

/**
 * This class is to show a bug on the IBM JDK around global allocations on MethodIDs*
 */
public class BugContext {

   private static final AtomicLong totalMaxIO = new AtomicLong(0);

   /**
    * This definition needs to match Version.h on the native sources.
    * <br>
    * Or else the native module won't be loaded because of version mismatches
    */
   private static final int EXPECTED_NATIVE_VERSION = 2;

   private static boolean loaded = false;

   public static boolean isLoaded() {
      return loaded;
   }

   private static boolean loadLibrary(final String name) {
      try {
         System.loadLibrary(name);
         return true;
      }
      catch (Throwable e) {
         e.printStackTrace();
         return false;
      }
   }

   static {
      loadLibrary("bug-native");
   }


   public native void hello(SubmitInformation info);

}
