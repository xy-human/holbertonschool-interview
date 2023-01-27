#!/usr/bin/python3
import sys

count = 0
file_size = 0
status_codes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                "405": 0, "500": 0}

try:
    for line in sys.stdin:
        try:
            data = line.split()
            file_size += int(data[-1])
            if data[-2] in status_codes:
                status_codes[data[-2]] += 1
            count += 1
            if count % 10 == 0:
                print("File size: {}".format(file_size))
                for k, v in sorted(status_codes.items()):
                    if v:
                        print("{}: {}".format(k, v))
        except Exception:
            pass
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(file_size))
    for k, v in sorted(status_codes.items()):
        if v:
            print("{}: {}".format(k, v))
