from conans import ConanFile, CMake, Embedded

class AversivePlusPlusProjectConan(ConanFile):
    name="project-2wheel-asserv"
    version="0.1"
    settings = "os", "compiler", "build_type", "arch", "target"
    requires = "AversivePlusPlus/0.1@AversivePlusPlus/dev"
    generators = "cmake"

    def imports(self):
        self.copy("*.cmake", dst="toolchain", src="toolchain")
        self.copy("*.ld", dst="toolchain/linker", src="linker")

    def build(self):
        cmake = CMake(self.settings)
        toolchain = '-DCMAKE_TOOLCHAIN_FILE=toolchain/sasiae.cmake'

        if self.settings.os == "Macos":
            self.run('cmake "%s" %s %s -DAPPLE=1' % (self.conanfile_directory, cmake.command_line, toolchain))
        else:
            self.run('cmake "%s" %s %s' % (self.conanfile_directory, cmake.command_line, toolchain))
        self.run('cmake --build . %s' % cmake.build_config)
