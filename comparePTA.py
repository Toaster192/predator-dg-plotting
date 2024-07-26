import glob
import sys
import os
import subprocess
import re
import signal

def preexec_function():
    # Ignore the SIGINT signal by setting the handler to the standard
    # signal handler SIG_IGN.
    signal.signal(signal.SIGINT, signal.SIG_IGN)

task_list = """
Juliet_Test/CWE121*fgets*.i
Juliet_Test/CWE121*large*.i
Juliet_Test/CWE121*rand*.i
Juliet_Test/CWE401*__int*.i
Juliet_Test/CWE401*__struct*.i
Juliet_Test/CWE401*__twoIntsStruct*.i
Juliet_Test/CWE415*.i
Juliet_Test/CWE476*_int*.i
Juliet_Test/CWE476*_long*.i
Juliet_Test/CWE476*_struct*.i
Juliet_Test/CWE590*.i
array-examples/*.i
array-fpi/*.i
array-memsafety-realloc/*.i
array-memsafety/*.i
ddv-machzwd/*.i
forester-heap/*.i
heap-manipulation/*.i
ldv-memsafety-bitfields/*.i
ldv-memsafety/*.i
ldv-regression/*.i
list-ext-properties/*.i
list-ext3-properties/*.i
list-properties/*.i
list-simple/*.i
locks/*.i
loop-acceleration/*.i
loop-industry-pattern/aiob_4*.i
loops-crafted-1/*.i
loops/*.i
memory-alloca/*.i
memsafety-bftpd/*.i
memsafety-broom/*.i
memsafety-ext/*.i
memsafety-ext2/*.i
memsafety-ext3/*.i
memsafety/*.i
ntdrivers-simplified/*.i
ntdrivers/*.i
pthread-memsafety/*.i
recursive-with-pointer/*.i
termination-15/*.i
termination-crafted-lit/HeizmannHoenickeLeikePodelski-ATVA2013-Fig7.i
termination-crafted/4BitCounterPointer.i
termination-crafted/Arrays*.i
termination-crafted/LexIndexValue*.i
termination-crafted/NonTermination*.i
termination-crafted/SyntaxSupportPointer*.i
termination-dietlibc/*.i
termination-memory-alloca/*.i
termination-memory-linkedlists/*.i
termination-recursive-malloc/*.i
verifythis/duplets.i
verifythis/elimination_max.i
verifythis/elimination_max_rec.i
verifythis/elimination_max_rec_onepoint.i
verifythis/lcp.i
verifythis/prefixsum_iter.i
verifythis/tree_del_iter.i
verifythis/tree_del_rec.i
verifythis/tree_max.i
"""

same_regex = r'Same: (\d+)'
more_accurate_regex = r'More accurate: (\d+)'
errors_regex = r'Errors: (\d+)'
segfault_regex = r'Segmentation fault\s+\(core dumped\)'
analysis_timer_regex = r'INFO: Pointer analysis took (\d+) sec (\d+) ms'
broken_dg_regex = r'Pointer Subgraph is broken'

same = 0
more_accurate = 0
errors = 0
broken = 0
broken_same = 0
broken_more_accurate = 0
broken_errors = 0

ran_successfully = 0
failed_to_run = 0

total_smg_time = 0
total_dg_time = 0
broken_smg_time = 0
broken_dg_time = 0

paths = []

failed_paths = []
skipped_paths = []
broken_paths = []
segfault_paths = []
skipped = 0
timeouted = 0
segfaults = 0

if "sv-benchmark" in sys.argv[1]:
    for task in task_list.split():
        paths += list(glob.iglob(sys.argv[1] + task))
else:
    for path in glob.iglob(sys.argv[1] + '**/*.c', recursive=True):
        if os.path.islink(path) and not os.path.exists(os.path.realpath(path)):
            continue
        paths.append(path)

num = len(paths)
i = 0

for path in paths:
    i += 1
    #print(path)
    try:
        cp_test = subprocess.run(['cp', path, "."], check=True, text=True)
        filename = os.path.basename(path)
        print(f"{i}/{num} - {path}")
        test_run = subprocess.run(['bash', '/home/toaster/school/predator-dg-plotting/smg_pta_test.sh', filename], check=True, text=True, capture_output=True, timeout=300, preexec_fn=preexec_function)
    except subprocess.TimeoutExpired:
        print("Timeout!")
        timeouted += 1
        continue
    except KeyboardInterrupt:
        break
    except:
        print("Skipped!")
        skipped += 1
        skipped_paths.append(path)
        continue
    #print(test_run.stdout)
    #print(test_run.stderr)
    out = test_run.stdout
    err = test_run.stderr

    timers = re.findall(analysis_timer_regex, err)
    if not timers:
        segfault = re.findall(segfault_regex, err)
        if segfault:
            print("Predator segfaulted")
            segfaults += 1
            segfault_paths.append(path)
        else:
            failed_to_run += 1
            print("Failed to run")
            failed_paths.append(path)
        continue

    ran_successfully += 1
    print("Ran successfuly")
    try:
        current_smg_time = 1000 * int(timers[0][0]) + int(timers[0][1])
        current_dg_time = 1000 * int(timers[1][0]) + int(timers[1][1])
    except IndexError:
        print("DG segfaulted")
        broken += 1
        broken_paths.append(path)
        continue

    same_cnt = re.search(same_regex, out)
    more_accurate_cnt = re.search(more_accurate_regex, out)
    errors_cnt = re.search(errors_regex, out)

    broken_cnt = re.search(broken_dg_regex, err)
    if broken_cnt:
        print("Found a broken dg graph, ignoring results")
        broken += 1
        broken_paths.append(path)
        broken_same += int(same_cnt.group(1))
        broken_more_accurate += int(more_accurate_cnt.group(1))
        broken_errors += int(errors_cnt.group(1))
        broken_smg_time += current_smg_time
        broken_dg_time += current_dg_time
    else:
        same += int(same_cnt.group(1))
        more_accurate += int(more_accurate_cnt.group(1))
        errors += int(errors_cnt.group(1))
        total_smg_time += current_smg_time
        total_dg_time += current_dg_time

    print("Stats:")
    print(same, more_accurate, errors, total_smg_time, total_dg_time)
    print(broken_same, broken_more_accurate, broken_errors, broken_smg_time, broken_dg_time)

    print("Total stats:")
    print(ran_successfully, failed_to_run, segfaults, skipped, timeouted, broken)


print("Paths:")
print(failed_paths)
print(skipped_paths)
print(broken_paths)
print(segfault_paths)

print("Final stats:")
print(same, more_accurate, errors, total_smg_time, total_dg_time)
print(broken_same, broken_more_accurate, broken_errors, broken_smg_time, broken_dg_time)
print(ran_successfully, failed_to_run, segfaults, skipped, timeouted, broken)
