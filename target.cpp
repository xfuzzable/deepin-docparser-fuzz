
#include <docparser/docparser.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>

extern "C" void xfuzz_test_one(char *Data, size_t DataSize) {
    std::string filename = "__xfuzz_test." FILE_EXT;
    FILE *f1 = fopen(filename.c_str(), "w");
    if (f1 == NULL) {
      printf("Cannot open file: %s\n", strerror(errno));
      return;
    }
    size_t r1 = fwrite(Data, 1, DataSize, f1);
    fclose(f1);
    auto dp = DocParser();
    auto r = dp.convertFile(filename);
    printf("%s\n", r.c_str());
}
