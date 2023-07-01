//pragma
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
compile: g++ -std = c++17 - I . - Dakifpathan - o "%e" "%f"
                    build: g++ -std = c++17 - DHFTF - Wshadow - o "%e" "%f"
                                      - g - fsanitize = address - fsanitize = undefined
                                          - D_GLIBCXX_DEBUG
                                          run: "./%e"
//for sublime
{
"cmd" : ["g++ -std=c++14 $file_name -o
	$file_base_name && timeout 6s
	./$file_base_name<in>out"],
"selector" : "source.c, source.cpp, source.Cc",
"shell": true,
"working_dir" : "$file_path"
}
//windows
{
"cmd": ["g++.exe", "-std=c++14", "${file}", "-o",
	"${file_base_name}.exe", "&&",
	"${file_base_name}.exe<in>out"],
"shell": true,
"working_dir": "$file_path",
"selector": "source.cpp, source.c, source.c++, source.cc"
}