const validateDirectory = (directoryLocation) => {
	if (!directoryLocation.includes(":\\")) return false;
	const [directory, ...remaningDirectoryLocation] = directoryLocation.split(":\\");
	if (remaningDirectoryLocation.length > 1) return false;
	const folderFilePath = remaningDirectoryLocation[0];
	const foldersAndFilesList = folderFilePath.split("\\");
	
	let isMatched = false;
	for (const file of foldersAndFilesList) {
		if (file.includes(".")) {
			if (isMatched) return false;
			isMatched = true;
		}
	}


	return true;
};

console.log(validateDirectory("C:\\hello\\world\\tand.js"));