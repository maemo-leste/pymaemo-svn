#!/bin/usr/python2.5

import abook

def main():

    abook.init("account_get", "0.0.1", False)

    account = abook.account_get("", "", "")

if __name__ == "__main__":
    main()
