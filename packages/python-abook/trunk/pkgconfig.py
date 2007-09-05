import subprocess

def run_pkg_config(args):
    proc = subprocess.Popen(
        ["pkg-config"]+args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    result, error = proc.communicate()
    retcode = proc.returncode

    return result.strip(), error.strip(), retcode

def list_all():
    all = run_pkg_config(["--list-all"])
    libs_full = all[0]

    libs = []
    for line in libs_full.split('\n'):
        name = line.split()[0]
        libs.append(name)

    return libs

def version():
    return run_pkg_config(["--version"])[0]

def modversion(name):
    return run_pkg_config(["--modversion", name])[0]

def exists(name):
    out, err, ret = run_pkg_config(["--exists", name])
    return ret == 0

def cflags(name):
    full_inc = run_pkg_config(["--cflags", name])[0]
    includes = [x for x in full_inc.split()]
    return includes

def libs(name):
    full_inc = run_pkg_config(["--libs", name])[0]
    includes = [x for x in full_inc.split()]
    return includes

def variable(pkg_name, variable_name):
    return run_pkg_config(["--variable=%s" % variable_name, pkg_name])[0]
