<<<<<<< HEAD
packages:=boost openssl libevent zeromq
native_packages := native_ccache

qt_native_packages = native_protobuf
qt_packages = qrencode protobuf zlib
=======
packages:=boost openssl libevent
darwin_packages:=zeromq
linux_packages:=zeromq
native_packages := native_ccache native_comparisontool

qt_native_packages = native_protobuf
qt_packages = qrencode protobuf
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

qt_x86_64_linux_packages:=qt expat dbus libxcb xcb_proto libXau xproto freetype fontconfig libX11 xextproto libXext xtrans
qt_i686_linux_packages:=$(qt_x86_64_linux_packages)
qt_arm_linux_packages:=$(qt_x86_64_linux_packages)
<<<<<<< HEAD
qt_aarch64_linux_packages:=$(qt_x86_64_linux_packages)
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

qt_darwin_packages=qt
qt_mingw32_packages=qt

<<<<<<< HEAD
=======

>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
wallet_packages=bdb

upnp_packages=miniupnpc

darwin_native_packages = native_biplist native_ds_store native_mac_alias

ifneq ($(build_os),darwin)
darwin_native_packages += native_cctools native_cdrkit native_libdmg-hfsplus
endif
