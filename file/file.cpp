#include <file/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

File::File(const std::string &file_path) :
    path(file_path),
    descriptor(-1)
{}

File::~File()
{
    Close();
}

void File::Open()
{
    descriptor = open(path.c_str(), O_CREAT | O_RDWR);
}

void File::Close()
{
    close(descriptor);
}

std::vector<uint8_t> File::Read(size_t size)
{
 	std::vector<uint8_t> buffer(size);
 	read(descriptor, buffer.data(), size);
 	return buffer;
}

void File::Write(const std::vector<uint8_t> &data)
{
    write(descriptor, data.data(), data.size());
}
