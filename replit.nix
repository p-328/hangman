{ pkgs }: {
	deps = [
		pkgs.sshpass
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}