package=native_ds_store
<<<<<<< HEAD
$(package)_version=1.1.0
$(package)_download_path=https://bitbucket.org/al45tair/ds_store/get
$(package)_download_file=v$($(package)_version).tar.bz2
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=921596764d71d1bbd3297a90ef6d286f718794d667e4f81d91d14053525d64c1
=======
$(package)_version=c80c23706eae
$(package)_download_path=https://bitbucket.org/al45tair/ds_store/get
$(package)_download_file=$($(package)_version).tar.bz2
$(package)_file_name=$(package)-$($(package)_version).tar.bz2
$(package)_sha256_hash=ce1aa412211610c63d567bbe3e06213006a2d5ba5d76d89399c151b5472cb0da
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
$(package)_install_libdir=$(build_prefix)/lib/python/dist-packages
$(package)_dependencies=native_biplist

define $(package)_build_cmds
    python setup.py build
endef

define $(package)_stage_cmds
    mkdir -p $($(package)_install_libdir) && \
    python setup.py install --root=$($(package)_staging_dir) --prefix=$(build_prefix) --install-lib=$($(package)_install_libdir)
endef
