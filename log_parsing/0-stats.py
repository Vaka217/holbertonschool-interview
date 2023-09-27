#!/usr/bin/python3
"""Log Parsing Module. Reads stdin line by line and computes metrics"""

import sys
import re
import signal


pattern = r'^(\d+\.\d+\.\d+\.\d+) - \[(' \
          r'\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{6})\] ' \
          r'"([A-Z]+ [^"]+)" (\d+) (\d+)$'
total_size = 0
status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
current_status_codes = []

try:
    for i, line in enumerate(sys.stdin):
        match = re.match(pattern, line)
        if not match:
            continue
        total_size += int(re.findall(r'\d+', line)[15])
        status_code = re.findall(r'\d+', line)[14]
        if status_code in status_codes:
            current_status_codes.append(status_code)
        if i % 10 == 0 and i > 0:
            print("File size:", total_size)
            for status_code in status_codes:
                if (current_status_codes.count(status_code) > 0):
                    print(f"{status_code}: {current_status_codes.count(status_code)}")
except KeyboardInterrupt:
    pass
finally:
    print("File size:", total_size)
    for status_code in status_codes:
        count = current_status_codes.count(status_code)
        if (current_status_codes.count(status_code) > 0):
            print(f"{status_code}: {count}")
    sys.exit()
