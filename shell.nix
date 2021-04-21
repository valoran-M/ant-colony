with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "poyuterm-dev-environment";
    buildInputs = [ pkgconfig cmake doctest SDL2];
}