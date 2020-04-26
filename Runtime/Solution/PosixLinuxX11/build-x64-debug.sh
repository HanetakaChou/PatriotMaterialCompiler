#!/bin/bash

cd "$(dirname "$(readlink -f "${0}")")"

target_name="PTMatC.bundle"
target_name_lib1="libPTMatC.so"
int_dir="obj/local/x86_64"
out_dir="../../../Binary/x64/Debug"

# flex bison
flex -X -o ../../Private/MatC/MDL/MDLScanner.inl ../../Private/MatC/MDL/MDLScanner.l   
bison -y -o ../../Private/MatC/MDL/MDLParser.inl -p mdl_yy ../../Private/MatC/MDL/MDLParser.y -L C 

# build by ndk
rm -rf obj
rm -rf libs
ndk-build APP_DEBUG:=true APP_ABI:=x86_64 NDK_PROJECT_PATH:=null NDK_OUT:=obj NDK_LIBS_OUT:=libs NDK_APPLICATION_MK:=Application.mk APP_BUILD_SCRIPT:=LinuxX11.mk

# before execute change the rpath to \$ORIGIN  
chrpath -r '$ORIGIN' ${int_dir}/${target_name}
chrpath -r '$ORIGIN' ${int_dir}/${target_name_lib1}

# mkdir the out dir if necessary
mkdir -p ${out_dir}

# copy the unstriped so to out dir
rm -rf ${out_dir}/${target_name}
cp -f ${int_dir}/${target_name} ${out_dir}/
rm -rf ${out_dir}/${target_name_lib1}
cp -f ${int_dir}/${target_name_lib1} ${out_dir}/

# copy the dep libs to out dir  
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libc.so ${out_dir}
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libdl.so ${out_dir}
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libm.so ${out_dir}
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libc++.so ${out_dir}/
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libstdc++.so ${out_dir}/  
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libc++_shared.so ${out_dir}/  
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libLLVM-8.so ${out_dir}/  

# copy the gdb related
cp -f libs/x86_64/gdbserver ${out_dir}/
cp -f libs/x86_64/gdb.setup ${out_dir}/

# place the linker at cwd   
cp -f ../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/linker ${out_dir}/ 
cd ${out_dir}

# execute the generated ${target_name}  
./gdbserver :27177 ./${target_name}