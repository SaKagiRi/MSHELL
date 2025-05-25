{
  description = "minishell flake for exact dependency lock";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.11";
    utils.url = "github:numtide/flake-utils";
    flake-compat.url = "https://flakehub.com/f/edolstra/flake-compat/1.tar.gz";
  };

  outputs = { self, nixpkgs, utils, flake-compat }: utils.lib.eachDefaultSystem (system:
  let
    pkgs = import nixpkgs {
      inherit system;
      config = {
        allowUnfree = true;
      };
      
    };
    stdenv = pkgs.clangStdenv;
  in
  {
	
    devShells.default = stdenv.mkDerivation {
      name = "minishell-nix";
      src = ./srcs;
      buildInputs = with pkgs; [
        clang
        # clang-tools
        readline
        ncurses
        pkg-config
      ];
      shellHook = ''
      '';
    };
  });
} 

