function _header_get_padding()
{
    local char=$1
    if [ "${char}" == "*" ]; then
        >&2 echo 'Error: Do no use the '*' character here ! It has weird effect with "printf".'
        exit 2
    fi
    printf '%0.1s' ${char}{1..300}
}
function _header_left()
{
    local text=$1
    local pad_char=$2
    local columns=$(tput cols)

    local padding=$(_header_get_padding "${pad_char}")
    local right=$(( $columns - 1 - ${#text} ))

    printf '%s %*.*s\n' "${text}" 0 "${right}" "${padding}"
}
