-- double clicking
on run
    tell application "Finder" to get container of (path to me) as string
    set script_path to quoted form of POSIX path of result

    -- Tell Terminal to run AltairZ80 from the command line
    -- Use the script's directory as the current directory
    tell application "Terminal"
        activate
        do script "cd " & script_path & " ; ./AltairZ80.app/Contents/MacOS/AltairZ80 ; exit"
    end tell
end run

-- dropping a SIMH command file
on open names
    tell application "Finder" to get container of (path to me) as string
    set script_path to quoted form of POSIX path of result

    -- Tell Terminal to run AltairZ80 from the command line
    -- Use the script's directory as the current directory
    -- Pass the dropped files to the application
    tell application "Terminal"
        activate
        do script "cd " & script_path & " ; ./AltairZ80.app/Contents/MacOS/AltairZ80 " & (quoted form of POSIX path of item 1 of names) & " ; exit"
    end tell
end open
