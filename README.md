# CodeSmithy Debian Repository Tools

This project contains tools to manage Debian repositories.

See https://earthly.dev/blog/creating-and-hosting-your-own-deb-packages-and-apt-repo/ and
https://wiki.debian.org/DebianRepository.

The repository format is defined here: https://wiki.debian.org/DebianRepository/Format.

deb <uri> <distribution> [component1] [component2] [...]
e.g. deb https://deb.debian.org/debian stable main contrib non-free

<uri> specifies the root of the archive referred to as $ARCHIVE_ROOT.

The distribution part ('stable' in this case) specifies a subdirectory in $ARCHIVE_ROOT/dists so in this case
https://deb.debian.org/debian/dists/stable. distribution typically corresponds to Suite or Codename specified in the
Release files.

To download packages from a repository apt would download an InRelease or Release file from the
$ARCHIVE_ROOT/dists/$DISTRIBUTION directory e.g. https://deb.debian.org/debian/dists/stable/(In)Release.

The Release file lists the index files for the distribution and their hashes (the index file listed are relative to Release file location).

To download the index of the main component, apt would scan the Release file for hashes of files in the main directory. eg. https://deb.debian.org/debian/dists/stable/main/binary-i386/Packages.gz which would be listed in https://deb.debian.org/debian/dists/stable/Release as main/binary-i386/Packages.gz.

So based on the above a repo looks like:
<root>/dists/stable/Release
<root>/dists/stable/main/binary-amd64/Packages

Binary package indices are in binary-$arch subdirectory of the component directories. Source indices are in source subdirectory. 

## License

Copyright (c) 2020-2024 Xavier Leclercq

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
