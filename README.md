# simple-JNI-bug
This is a simple project showing a bug with IBM JDK

To replicate the issue use cmake:

```sh
cmake .
make
```


Then execute the tests:


```sh
mvn install
```


You should see somethng like this (tested on Linux 64 bit, in several linux versions):


```
Running org.apache.activemq.artemis.bug.test.BugTest
method inside
Unhandled exception
Type=Segmentation error vmState=0x00000000
J9Generic_Signal_Number=00000004 Signal_Number=0000000b Error_Value=00000000 Signal_Code=00000001
Handler1=00007FA40C906D90 Handler2=00007FA40C24B3F0 InaccessibleAddress=0000000000000300
RDI=00000000008C2500 RSI=000000000098FCC0 RAX=0000000000000310 RBX=0000000000000000
RCX=0000000000000000 RDX=00007FA40D7C7390 R8=00007FA40D7C7390 R9=00007FA40C96CA58
R10=00007FA40D7C70C8 R11=00007FA40D7C70C0 R12=0000000000A894D8 R13=00000000FFF389A0
R14=0000000000010101 R15=00007FA40D7C7580
RIP=00007FA40C90BC56 GS=0000 FS=0000 RSP=00007FA40D7C70D0
EFlags=0000000000210246 CS=0033 RBP=00007FA40D7C7380 ERR=0000000000000004
TRAPNO=000000000000000E OLDMASK=0000000000000000 CR2=0000000000000300
SUREFIRE-859: xmm0 00007fa408065bf0 (f: 134634480.000000, d: 6.933840e-310)
SUREFIRE-859: xmm1 00000000008c2500 (f: 9184512.000000, d: 4.537752e-317)
SUREFIRE-859: xmm2 000000000098fd50 (f: 10026320.000000, d: 4.953660e-317)
SUREFIRE-859: xmm3 0000000000a45018 (f: 10768408.000000, d: 5.320300e-317)
SUREFIRE-859: xmm4 0000000000000005 (f: 5.000000, d: 2.470328e-323)
SUREFIRE-859: xmm5 0000000000a894d8 (f: 11048152.000000, d: 5.458512e-317)
SUREFIRE-859: xmm6 0000000000000001 (f: 1.000000, d: 4.940656e-324)
SUREFIRE-859: xmm7 0000000000000001 (f: 1.000000, d: 4.940656e-324)
SUREFIRE-859: xmm8 0000000000000000 (f: 0.000000, d: 0.000000e+00)
SUREFIRE-859: xmm9 0000000000000000 (f: 0.000000, d: 0.000000e+00)
SUREFIRE-859: xmm10 0000000000000000 (f: 0.000000, d: 0.000000e+00)
SUREFIRE-859: xmm11 0000000000000000 (f: 0.000000, d: 0.000000e+00)
SUREFIRE-859: xmm12 0000000000000000 (f: 0.000000, d: 0.000000e+00)
SUREFIRE-859: xmm13 402bb9d3beb8c600 (f: 3199780352.000000, d: 1.386294e+01)
SUREFIRE-859: xmm14 bc675d04a2d1552f (f: 2731627776.000000, d: -1.013224e-17)
SUREFIRE-859: xmm15 402bb9d3beb8c600 (f: 3199780352.000000, d: 1.386294e+01)
Module=/opt/ibm/java-x86_64-80/jre/lib/amd64/compressedrefs/libj9vm28.so
Module_base_address=00007FA40C893000
Target=2_80_20150630_255633 (Linux 4.0.4-301.fc22.x86_64)
CPU=amd64 (8 logical CPUs) (0x2eee3a000 RAM)
----------- Stack Backtrace -----------
(0x00007FA40C90BC56 [libj9vm28.so+0x78c56])
(0x00007FA40C920ECA [libj9vm28.so+0x8deca])
---------------------------------------
SUREFIRE-859: JVMDUMP039I Processing dump event "gpf", detail "" at 2015/09/30 12:54:02 - please wait.
JVMDUMP032I JVM requested System dump using '/work/simple-JNI-bug/core.20150930.125402.26808.0001.dmp' in response to an event
JVMPORT030W /proc/sys/kernel/core_pattern setting "|/usr/libexec/abrt-hook-ccpp %s %c %p %u %g %t %e %P %i" specifies that the core dump is to be piped to an external program.  Attempting to rename either core or core.26834.
JVMDUMP010I System dump written to /work/simple-JNI-bug/core.20150930.125402.26808.0001.dmp
JVMDUMP032I JVM requested Java dump using '/work/simple-JNI-bug/javacore.20150930.125402.26808.0002.txt' in response to an event
JVMDUMP010I Java dump written to /work/simple-JNI-bug/javacore.20150930.125402.26808.0002.txt
JVMDUMP032I JVM requested Snap dump using '/work/simple-JNI-bug/Snap.20150930.125402.26808.0003.trc' in response to an event
JVMDUMP010I Snap dump written to /work/simple-JNI-bug/Snap.20150930.125402.26808.0003.trc
JVMDUMP007I JVM Requesting JIT dump using '/work/simple-JNI-bug/jitdump.20150930.125402.26808.0004.dmp'
#JITDUMP:  vmThread=00000000008E4D00 Recursive crash occurred. Aborting JIT dump.JVMDUMP010I JIT dump written to /work/simple-JNI-bug/jitdump.20150930.125402.26808.0004.dmp
SUREFIRE-859: JVMDUMP013I Processed dump event "gpf", detail "".
```
