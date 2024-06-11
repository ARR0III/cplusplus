#include <iostream>
#include <cstdio>

class File {
  FILE * file;
  char * filename;

  unsigned long long size;
  unsigned long long count_str;

public:
  File(char * str = 0, bool rw = false) {
    file = 0;
    filename = str;

    if (str) {
      file = fopen(str, rw ? "r+b" : "rb");
    }

    size      = 0;
    count_str = 0;
  }

  bool Open(char *, bool);
  bool Close();

  char * GetName() const ;
  inline unsigned long long Size();
  inline unsigned long long GetSize() const;

  ~File() {
    if (file) {
      fclose(file);
    }

    filename  = 0;
    file      = 0;
    size      = 0;
    count_str = 0;
  }
};

bool File::Open(char * str = 0, bool rw = false) {
  if (file) {
    return true;
  }

  if (str) {
    file = fopen(str, rw ? "r+b" : "rb");
  }

  if (file) {
    filename = str;
  }
  
  return (file ? true : false);
}

bool File::Close() {
  int cl = 0;

  if (file) {
    cl = fclose(file);
  }

  file      = 0;
  filename  = 0;

  return (cl ? false : true);
}

inline char * File::GetName() const {
  return filename;
}

inline unsigned long long File::GetSize() const {
  return size;
}

unsigned long long File::Size() {
  if (!file) return 0;

  size = fseek(file, 0, SEEK_END);

  if ((int)size == -1) return 0;

  size = ftell(file);

  if (fseek(file, 0, SEEK_END) == -1) {
    return (size = 0);
  }

  return size;
}

int main(int argc, char * argv[]) {
  File * files = new File[16];

  for (int i = 1; argv[i] && i <= 16; i++) {
    if (!files[i].Open(argv[i])) {
      std::cout << "File " << files[i].GetName() << " not found!\n";
      continue;
    }

    std::cout << "Size of file " << files[i].GetName() << " : " << files[i].Size() << '\n';
  }

  delete [] files;
  return 0;
}

