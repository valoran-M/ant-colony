with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "poyuterm-dev-environment";
    buildInputs = [ pkg-config cmake doctest ];
}