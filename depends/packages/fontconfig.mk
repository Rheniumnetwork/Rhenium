package=fontconfig
<<<<<<< HEAD
$(package)_version=2.12.1
$(package)_download_path=http://www.freedesktop.org/software/fontconfig/release/
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=b449a3e10c47e1d1c7a6ec6e2016cca73d3bd68fbbd4f0ae5cc6b573f7d6c7f3
=======
$(package)_version=2.11.1
$(package)_download_path=http://www.freedesktop.org/software/fontconfig/release/
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=dc62447533bca844463a3c3fd4083b57c90f18a70506e7a9f4936b5a1e516a99
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
$(package)_dependencies=freetype expat

define $(package)_set_vars
  $(package)_config_opts=--disable-docs --disable-static
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

<<<<<<< HEAD
# 2.12.1 uses CHAR_WIDTH which is reserved and clashes with some glibc versions, but newer versions of fontconfig
# have broken makefiles which needlessly attempt to re-generate headers with gperf.
# Instead, change all uses of CHAR_WIDTH, and disable the rule that forces header re-generation.
# This can be removed once the upstream build is fixed.
define $(package)_build_cmds
  sed -i 's/CHAR_WIDTH/CHARWIDTH/g' fontconfig/fontconfig.h src/fcobjshash.gperf src/fcobjs.h src/fcobjshash.h && \
  sed -i 's/fcobjshash.h: fcobjshash.gperf/fcobjshash.h:/' src/Makefile && \
=======
define $(package)_build_cmds
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef
