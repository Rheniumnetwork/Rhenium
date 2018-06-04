package=zeromq
<<<<<<< HEAD
$(package)_version=4.1.5
$(package)_download_path=https://github.com/zeromq/zeromq4-1/releases/download/v$($(package)_version)/
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=04aac57f081ffa3a2ee5ed04887be9e205df3a7ddade0027460b8042432bdbcf
$(package)_patches=9114d3957725acd34aa8b8d011585812f3369411.patch 9e6745c12e0b100cd38acecc16ce7db02905e27c.patch

define $(package)_set_vars
  $(package)_config_opts=--without-documentation --disable-shared --without-libsodium --disable-curve
=======
$(package)_version=4.1.4
$(package)_download_path=http://download.zeromq.org
$(package)_file_name=$(package)-$($(package)_version).tar.gz
$(package)_sha256_hash=e99f44fde25c2e4cb84ce440f87ca7d3fe3271c2b8cfbc67d55e4de25e6fe378

define $(package)_set_vars
  $(package)_config_opts=--without-documentation --disable-shared --without-libsodium
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
  $(package)_config_opts_linux=--with-pic
  $(package)_cxxflags=-std=c++11
endef

<<<<<<< HEAD
define $(package)_preprocess_cmds
  patch -p1 < $($(package)_patch_dir)/9114d3957725acd34aa8b8d011585812f3369411.patch && \
  patch -p1 < $($(package)_patch_dir)/9e6745c12e0b100cd38acecc16ce7db02905e27c.patch && \
  ./autogen.sh
endef

=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE) libzmq.la
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install-libLTLIBRARIES install-includeHEADERS install-pkgconfigDATA
endef

define $(package)_postprocess_cmds
  rm -rf bin share
endef
