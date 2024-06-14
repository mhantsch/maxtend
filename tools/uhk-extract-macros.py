import argparse
import sys
import json
import re

def printMacroDetails(m):
    if m['name'][:5]=='uname' or m['name']=='learn_hostmap':
        print(m['name']+" -- suppressed\n")
        return
    print(m['name']+":")
    if args.debug:
        print(m['macroActions'])
    for ma in m['macroActions']:
        if ma['macroActionType'] ==  'command':
            print('```')
            print(ma['command'])
            print('```')
        else:
            print(ma['macroActionType'], '...')
    print('')

def main():
    global args

    parser= argparse.ArgumentParser(description='extract macros from an exported uhk configuration file (json)')
    parser.add_argument('--debug', dest='debug', action='store_true', default=False, help='show debugging information for developers')
    parser.add_argument('--match', dest='match', action='store', default=None, help='extract macros with matching names (otherwise, all macro names are displayed, but no details)')
    parser.add_argument('--inputfile', dest='inputfile', action='store', default=None, help='read this input file (otherwise, reads stdin)')
    args= parser.parse_args()

    if args.debug:
        print('Debug output will be generated.')

    if args.inputfile:
        file= open(args.inputfile, "r", encoding='utf-8')
    else:
        file= sys.stdin

    data= json.load(file)

    if args.debug:
        for i in data:
            print(i)

    print("Config is for userConfig v"+str(data['userConfigMajorVersion'])+'.'+str(data['userConfigMinorVersion'])+'.'+str(data['userConfigPatchVersion']))

    if args.match==None:
        print("\nIncluded keymaps:")
        for i in data['keymaps']:
            print(i['abbreviation'], i['name'], '(default)' if i['isDefault'] else '')

        print("\nIncluded macros:")
    for i in data['macros']:
        if args.match==None:
            print(i['name'])
        elif re.search(args.match, i['name']):
            printMacroDetails(i)

    file.close()

if __name__ == '__main__':
    main()