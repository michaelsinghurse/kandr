import subprocess
import time

FIRST = './first.out'
SECOND = './second.out'
TRIALS = 10

def get_time(program):
    times = []

    for _i in range(TRIALS):
        t0 = time.time()

        cat = subprocess.Popen(['cat', 'data.csv'], stdout=subprocess.PIPE)
        subprocess.run(program, stdin=cat.stdout, stdout=subprocess.DEVNULL)

        t1 = time.time()

        times.append(t1-t0)

    return round(sum(times) / len(times) * 1000, 2)

t1 = get_time(FIRST)
t2 = get_time(SECOND)

print(f'time first: {t1} ms')
print(f'time second: {t2} ms')
