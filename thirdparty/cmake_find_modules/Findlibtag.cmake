# find libtag
find_path(LIBTAG_DIR
          NAMES
          src/tag.h
          HINTS
          ${NAP_ROOT}/modules/naplibtag/thirdparty/libtag
          )


set(LIBTAG_INCLUDE_DIR ${LIBTAG_DIR}/src)
set(LIBTAG_LIBRARY_DIR ${LIBTAG_DIR}/linux/${ARCH}/lib)
set(LIBTAG_LIBRARIES_RELEASE ${LIBTAG_LIBRARY_DIR}/libtag.so)
set(LIBTAG_LIBRARIES_DEBUG ${LIBTAG_LIBRARY_DIR}/libtag.so)

include(FindPackageHandleStandardArgs)

# handle the QUIETLY and REQUIRED arguments and set RTMIDI_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libtag REQUIRED_VARS
    LIBTAG_DIR
    LIBTAG_LIBRARY_DIR
    LIBTAG_INCLUDE_DIR
    LIBTAG_LIBRARIES_RELEASE
    LIBTAG_LIBRARIES_DEBUG)
