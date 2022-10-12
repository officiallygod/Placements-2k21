import csv
import sys
import pathlib
import xml.etree. ElementTree as XT

def xml_to_csv(input, csv_name) -> None:
    tree = XT.parse(input)
    root = tree.getroot()
    with open(csv_name, 'w') as csv_file:
        writer = csv.writer(csv_file)
        headers = (child.tag for child in root[0])
        writer.writerow(headers)
        num_records = len(root)
        for record in range (num_records):
            for child in root[record]:
                rec = child.text
                # rec = (child.text for child in root[record])
                print (rec)
                writer.writerow(rec)

if _name_ == ‘_main_’:
    try:
        input = sys.argv[1]
        csv_name = sys.argv[2]
        print (input, type(input))
    except IndexError:
        sys.exit('two arguments required' )

    with pathlib.Path(input) as xml_file:
        if xml_file.isfile() :
            xml_to_csv(input, csv_name)
        else:
            sys. exit( 'Did not find {file path}')