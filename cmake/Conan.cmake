#message("++++++enabled conan.cmake..11begin${${PROJECT_NAME}_ENABLE_CONAN}")
if(${PROJECT_NAME}_ENABLE_CONAN)
  #
  # Setup Conan requires and options here:
  #
  
  message("enabled conan.cmake..cool ...11${CONAN_DISABLE_CHECK_COMPILER}")
  set(CONAN_DISABLE_CHECK_COMPILER True CACHE BOOL "" FORCE )
  set(${PROJECT_NAME}_CONAN_REQUIRES 
  #"libuv/1.34.2"
  #"zlib/1.2.12"
  "poco/1.12.1"
  "spdlog/1.9.2"
  #"catch2/3.1.0"
  "libevent/2.1.12"
  "openssl/1.1.1d"
  )
  set(${PROJECT_NAME}_CONAN_OPTIONS "")
  #
  set(CONAN_LOCAL_CMAKESOURCE cmake/3rd-cmake/conan.cmake)
  #
  # If `conan.cmake` (from https://github.com/conan-io/cmake-conan) does not exist, download it.
  # copy from local folder from now on.
  #
#  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#    message(
#      STATUS
#      "Downloading conan.cmake from https://github.com/conan-io/cmake-conan..."
#    )
#    file(
#      DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.18/conan.cmake"
#      "${CMAKE_BINARY_DIR}/conan.cmake"
#    )
#    message(STATUS "Cmake-Conan downloaded succesfully.")
#  endif()

  include("${CONAN_LOCAL_CMAKESOURCE}")

 conan_add_remote(
   NAME c23
   URL
   http://23.234.225.112:8082/artifactory/api/conan/conan
 )

  message("+++++++{${PROJECT_NAME}_CONAN_REQUIRES}")
  conan_cmake_run(
    REQUIRES
    ${${PROJECT_NAME}_CONAN_REQUIRES}
    OPTIONS
    ${${PROJECT_NAME}_CONAN_OPTIONS}
    BASIC_SETUP
    CMAKE_TARGETS # Individual targets to link to
    #SETTINGS compiler.cppstd=17
   # BUILD
   #  missing # build not prebuild pkg
  )

  conan_basic_setup()
  message("-=-=-=-=-${CMAKE_TARGETS}")
  message("++++++++++test::: ${CONAN_LIBS}")
  verbose_message("Conan is setup and all requires have been installed.")
endif()


  message("enabled conan.cmake..cool ...11${CONAN_DISABLE_CHECK_COMPILER}")