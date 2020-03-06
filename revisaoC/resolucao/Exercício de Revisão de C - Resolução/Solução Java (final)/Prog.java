import java.io.*;
import java.util.*;

public class Prog {
    public static void main(String[] args) throws Exception {
        String nomeArquivo = null;

        if (args.length > 0) {
            nomeArquivo = args[0];
        }
        else {
            Scanner in = new Scanner(System.in);
            System.out.printf("Arquivo de entrada: ");
            nomeArquivo = in.nextLine();
            in.close();
        }

        Scanner scanner = new Scanner(new File(nomeArquivo));

        scanner.nextInt();
        scanner.nextLine();

        List<Aluno> alunos = new ArrayList<>();

        while (scanner.hasNextLine()) {
            double nota = scanner.nextDouble();
            String nome = scanner.nextLine().trim();
            alunos.add(new Aluno(nome, nota));
        }
        scanner.close();

        Collections.sort(alunos);

        double media = 0;
        for (Aluno aluno : alunos) {
            media += aluno.getNota();
        }
        media /= alunos.size();

        PrintWriter out = new PrintWriter(new File("saida.csv"));
        out.println("Nome,Nota,Situação");

        for (Aluno aluno : alunos) {
            String nome = aluno.getNome();
            double nota = aluno.getNota();
            
            if (nota > media) {
                System.out.println(nome);
            }

            if (nota >= 7.0) {
                out.printf("%s,%.2f,Aprovado\n", nome, nota);
            }
            else {
                out.printf("%s,%.2f,Prova Final\n", nome, nota);                
            }
        }

        out.close();
    }
}