#include "include.hpp"
#include "console.h"
#include "loops.h"

namespace fs = std::filesystem;


void startconsolethread() {
    std::thread t1([]() {
        while (true) {
            setconsole();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        });
    t1.detach();
}

void startAntiDebugThread() {
    std::thread t([]() {
        while (true) {
            antic();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        });
    t.detach();
}


std::string generateRandomString(int length, bool excludeVolume) {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (excludeVolume) {
        chars = "ABCDEF0123456789";
    }

    std::string randomStr;
    std::srand(std::time(nullptr));
    for (int i = 0; i < length; ++i) {
        randomStr += chars[std::rand() % chars.size()];
    }
    return randomStr;
}

bool CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
    std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

    if (!file_ofstream.write(address, size))
    {
        file_ofstream.close();
        return false;
    }

    file_ofstream.close();
    return true;
}

void moveFiles(const fs::path& source, const fs::path& destination) {
    if (!fs::exists(source) || !fs::is_directory(source)) {
        std::cerr << "The source directory does not exist or is not a directory." << std::endl;
        return;
    }

    if (!fs::exists(destination)) {
        std::cerr << "The destination directory does not exist." << std::endl;
        return;
    }

    if (source.root_name() == destination.root_name()) {
        std::cerr << "The destination is on the same disk. Specify a different disk." << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(source)) {
        if (entry.is_regular_file()) {
            fs::path file_path = entry.path();
            fs::path new_path = destination / file_path.filename();

            try {
                fs::rename(file_path, new_path);
                std::cout << "Moved: " << file_path << " to " << new_path << std::endl;
            }
            catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Error moving file " << file_path << ": " << e.what() << std::endl;
            }
        }
    }
}