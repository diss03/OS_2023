#!/bin/bash

ls -l -R / | grep '^-' >> "&1"
ls -l -R / | grep '^b' >> "&1"
ls -l -R / | grep '^c' >> "&1"
ls -l -R / | grep '^d' >> "&1"
ls -l -R / | grep '^l' >> "&1"
ls -l -R / | grep '^p' >> "&1"
ls -l -R / | grep '^s' >> "&1"
echo "Done!"
