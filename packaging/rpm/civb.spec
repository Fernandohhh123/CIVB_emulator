Name:           civb
Version:        0.0.1
Release:        1%{?dist}
Summary:        Simple 4-bit CPU emulator

License:        GPL-3.0-or-later
URL:            https://github.com/Fernandohhh123/CIVB_emulator
Source0:        %{name}-%{version}.tar.gz

BuildRequires:  gcc-c++
BuildRequires:  make 

%description
4-bit CPU emulator with a TUI-based interface

%prep
%autosetup -c %{name}-%{version}

%build
%set_build_flags
make %{?_smp_mflags} CXX="g++"


%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot} PREFIX=%{_prefix}


%files
%license COPYING
%doc readme
%{_bindir}/civb


%check
# no test suite aviable yet

%changelog
* Wed Sep 09 2026 Fernandoh <fernandopulpyto@gmail.com> - 0.0.1-1
- First functional version for Fedora.
