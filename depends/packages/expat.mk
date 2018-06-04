package=expat
<<<<<<< HEAD
$(package)_version=2.2.0
$(package)_download_path=https://downloads.sourceforge.net/project/expat/expat/$($(package)_version)
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=d9e50ff2d19b3538bd2127902a89987474e1a4db8e43a66a4d1a712ab9a504ff
=======
$(package)_version=2.1.1
$(package)_download_path=https://downloads.sourceforge.net/project/expat/expat/$($(package)_version)
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=aff584e5a2f759dcfc6d48671e9529f6afe1e30b0cd6a4cec200cbe3f793de67
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

define $(package)_set_vars
$(package)_config_opts=--disable-static
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef
