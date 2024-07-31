#!/bin/bash
#
# Script to add include guards to one or more C/C++ header files
#

# Function to check if an include guard is present
check_include_guard() {
    local HEADER_FILE="$1"
    HEADER_BASE=$(basename "${HEADER_FILE}")
    GUARD_NAME=$(echo "${HEADER_BASE}" | tr '[:lower:]' '[:upper:]' | tr '.' '_')
    local GUARD_START="#ifndef ${GUARD_NAME}"

    if grep -q "${GUARD_START}" "${HEADER_FILE}"; then
        return 0 # Guard found
    else
        return 1 # Guard not found
    fi
}

# Function to add an include guard to a header file
add_include_guard() {
    local HEADER_FILE="$1"
    HEADER_BASE=$(basename "${HEADER_FILE}")
    GUARD_NAME=$(echo "${HEADER_BASE}" | tr '[:lower:]' '[:upper:]' | tr '.' '_')

    echo "Adding include guard to '${HEADER_FILE}'..."

    {
        echo "#ifndef ${GUARD_NAME}"
        echo "#define ${GUARD_NAME}"
        echo ""
        cat "${HEADER_FILE}"
        echo ""
        echo "#endif // ${GUARD_NAME}"
    } >"temp.h"

    mv "temp.h" "${HEADER_FILE}"

    echo "Done."
}

inspect_file() {
    HEADER_FILE="$1"

    HEADER_BASE=$(basename "$HEADER_FILE")

    if [ ! -f "$HEADER_FILE" ]; then
        echo "Error: '$HEADER_FILE' is not a file."
        return 1
    fi

    if check_include_guard "$HEADER_FILE"; then
        echo "Include guard already present. Nothing to do."
        return
    fi
    add_include_guard "$HEADER_FILE"
}

# Main script execution
if [ -z "$1" ]; then
    echo "Usage: $0 <header_file.h> ..."
    exit 1
else
    for FILENAME in $@; do
        inspect_file $FILENAME
    done
fi
