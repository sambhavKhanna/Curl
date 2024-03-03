curl -o test.html $1
./scan < test.html > url.txt 
x=0
while IFS= read -r line; do
    image_name="image$((x+1)).jpeg"
    curl -o $image_name $line
    x=$((x+1))
done < "url.txt"