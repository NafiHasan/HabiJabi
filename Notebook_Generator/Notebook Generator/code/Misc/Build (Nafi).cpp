{
"cmd" : ["g++ -std=c++14 $file_name -o $file_base_name && timeout 6s ./$file_base_name<in>out"],
"selector" : "source.c, source.cpp, source.Cc",
"shell": true,
"working_dir" : "$file_path"
}