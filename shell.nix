with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "ant-sim-dev-environment";
    buildInputs = [ pkgconfig cmake doctest SDL2];
}