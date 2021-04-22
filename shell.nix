with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "an-sim-dev-environment";
    buildInputs = [ pkgconfig cmake doctest SDL2];
}