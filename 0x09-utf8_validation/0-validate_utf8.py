#!/usr/bin/python3
""" Validation UTF-8 information """


def validUTF8(data):
    """ Validation UTF-8 information """
    bytes_number = 0

    for i in data:
        byte = format(i, '#010b')[-8:]

        if bytes_number == 0:
            if byte[0] == '1':
                bytes_number = len(byte.split('0')[0])

            if bytes_number > 4 or bytes_number == 1:
                return False
            elif bytes_number == 0:
                continue
        else:
            if not (byte[0] == '1' and byte[1] == '0'):
                return False

        bytes_number = bytes_number - 1

    if bytes_number != 0:
        return False
    return True
