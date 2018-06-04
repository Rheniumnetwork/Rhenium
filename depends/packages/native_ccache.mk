package=native_ccache
<<<<<<< HEAD
$(package)_version=3.3.3
$(package)_download_path=https://samba.org/ftp/ccache
$(package)_file_name=ccache-$($(package)_version).tar.bz2
$(package)_sha256_hash=2985bc5e32ebe38d2958d508eb54ddcad39eed909489c0c2988035214597ca54
=======
$(package)_version=3.2.5
$(package)_download_path=http://samba.org/ftp/ccache
$(package)_file_name=ccache-$($(package)_version).tar.bz2
$(package)_sha256_hash=7a553809e90faf9de3a23ee9c5b5f786cfd4836bf502744bedb824a24bee1097
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

define $(package)_set_vars
$(package)_config_opts=
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

define $(package)_postprocess_cmds
  rm -rf lib include
endef
