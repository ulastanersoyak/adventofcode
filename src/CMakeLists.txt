foreach (YEAR RANGE 2015 2023)
  message("processing year: ${YEAR}")
  set(DIR_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${YEAR}")
  file(GLOB DAYS "${DIR_PATH}/day[0-9]*")  
  foreach(DAY ${DAYS})
    string(REGEX MATCH "day([0-9]+)$" DAY_MATCH "${DAY}")
    if(DAY_MATCH)
      set(DAY_NUMBER ${CMAKE_MATCH_1})
    endif()
    message(" processing day: ${DAY_NUMBER}")
    file(GLOB CPP_FILES "${DAY}/*.cpp")
    foreach(CPP_FILE ${CPP_FILES})
      message("  processing file: ${CPP_FILE}")
      string(REGEX MATCH "p([0-9]+)" PART_MATCH "${CPP_FILE}" MATCH 1)
      if(PART_MATCH)
        set(PART_NUMBER ${CMAKE_MATCH_1})
      endif()
      message("year:${YEAR}, day:${DAY_NUMBER},part:${PART_NUMBER}")
      set(TARGET_NAME "${YEAR}_${DAY_NUMBER}_Part${PART_NUMBER}")
      add_executable(${TARGET_NAME} ${CPP_FILE})
    endforeach()
  endforeach()
endforeach()
