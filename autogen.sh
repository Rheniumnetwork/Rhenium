#!/bin/sh
<<<<<<< HEAD
# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
set -e
srcdir="$(dirname $0)"
cd "$srcdir"
if [ -z ${LIBTOOLIZE} ] && GLIBTOOLIZE="`which glibtoolize 2>/dev/null`"; then
  LIBTOOLIZE="${GLIBTOOLIZE}"
  export LIBTOOLIZE
fi
<<<<<<< HEAD
which autoreconf >/dev/null || \
  (echo "configuration failed, please install autoconf first" && exit 1)
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
autoreconf --install --force --warnings=all
