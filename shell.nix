with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "ant-sim-dev-environment";
    buildInputs = [ pkg-config cmake doctest sfml ];
}